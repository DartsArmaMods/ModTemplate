#!/usr/bin/env python3
"""
Author: DartRuffian
Description:
  Builds the addon of the given file path.
"""

import sys
import os
import logger


def main() -> None:
    try:
        filepath = sys.argv[1]
        if not (filepath.startswith("addons") or filepath.startswith("optionals")):
            logger.log(logger.LogLevel.ERROR,
                       f"Failed to build: {filepath} is not an addon path")

        addon = filepath.split("\\")[1]
        logger.log(logger.LogLevel.INFO, f"Building addon: {addon}")
        os.system(f"hemtt ln sort")
        os.system(f"hemtt build --just {addon} --just translations")
    except KeyboardInterrupt:
        # Echo "nothing" so the next message is on a new line
        os.system("echo(")
        logger.log(logger.LogLevel.INFO, "Canceling build")


if __name__ == "__main__":
    main()
