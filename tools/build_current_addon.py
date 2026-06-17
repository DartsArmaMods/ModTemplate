#!/usr/bin/env python3
"""
Author: DartRuffian
Description:
  Builds the addon of the given file path.
"""

import sys
import os
import subprocess
import logger


def main() -> None:
    try:
        filepath = sys.argv[1]
        if not (filepath.startswith("addons") or filepath.startswith("optionals")):
            logger.log(logger.LogLevel.ERROR,
                       f"Failed to build: '{filepath}' is not an addon path")
            return

        # Translations should always be rebuilt, add it if current translation isn't translations
        addons = [filepath.split(os.sep)[1]]
        if addons[0].lower() != "translations":
            addons.append("translations")

        logger.log(logger.LogLevel.INFO,
                   f"Building addon(s): {", ".join(addons)}")

        command = ["hemtt", "build"]

        for addon in addons:
            command.extend(["--just", addon])

        subprocess.run(command)
    except KeyboardInterrupt:
        # Echo "nothing" so the next message is on a new line
        subprocess.run(["echo("])
        logger.log(logger.LogLevel.INFO, "Canceling build")


if __name__ == "__main__":
    main()
