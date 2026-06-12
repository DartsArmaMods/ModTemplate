#!/usr/bin/env python3
"""
Author: DartRuffian
Description:
  Creates a release; by default, bumps the minor version number and resets patch number.
  Use --major bumps major number and resets minor/patch numbers.
  Use --patch only bumps patch number.
"""

import os
import subprocess
import sys
import tomllib
import logger
import config_style_checker


def write_loadorder(prefix: str) -> int:
    """Write loadorder requiredAddons, so other addons can just use that as a requirement to load after all other addons. Does not cover subaddons. Returns number of addons included in loadorder"""
    addons: list[str] = []
    for folder in os.listdir("./addons"):
        # Shouldn't ever be loose files in addons folder
        if os.path.isfile(folder):
            continue

        content = ""
        with open(f"./addons/{folder}/config.cpp", "r") as f:
            content = f.read().lower()

        # Skip loadorder addon itself, or if addon is set to skip, or if it requires the loadorder itself
        if folder.lower() == "loadorder" or content.find("skipwhenmissingdependencies = 1") != -1 or content.find(f"{prefix}_loadorder") != -1:
            continue

        addons.append(folder)

    if addons:
        with open("./addons/loadorder/addons.hpp", "w") as f:
            for addon in addons:
                f.write(f'"{prefix}_{addon}",\n')
    else:
        logger.log(logger.LogLevel.WARN, "No addons found for loadorder!")

    return len(addons)


def main() -> None:
    if os.getcwd().endswith("tools"):
        os.chdir("..")

    prefix = ""
    with open(".hemtt/project.toml", "rb") as f:
        data = tomllib.load(f)
        prefix = data["prefix"]
    logger.log(logger.LogLevel.INFO, f"Main Prefix: '{prefix}'")

    if not "--skip-bump" in sys.argv:
        logger.log(logger.LogLevel.INFO, "Bumping version")

        bump_script = "minor"
        if "--major" in sys.argv:
            bump_script = "major"
        elif "--patch" in sys.argv:
            bump_script = "patch"
        subprocess.run(["hemtt", "script", f"update_{bump_script}.rhai"])

    logger.log(logger.LogLevel.INFO, "Writing loadorder requiredAddons")
    addon_count = write_loadorder(prefix)
    logger.log(logger.LogLevel.INFO,
               f"Wrote {addon_count} addons to addons/loadorder/addons.hpp")

    subprocess.run(["hemtt", "ln", "sort"])

    error_count = config_style_checker.main()
    if error_count > 0:
        logger.log(logger.LogLevel.ERROR,
                   f"{error_count} errors detected and must be fixed")
        return

    if not "--skip-release" in sys.argv:
        subprocess.run(["hemtt", "release"])


if (__name__ == "__main__"):
    main()
