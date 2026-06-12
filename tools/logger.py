#!/usr/bin/env python3
"""
Author: DartRuffian
Description:
  Handles writing log messages with colored text for different log levels
"""

from enum import Enum


class LogLevel(Enum):
    INFO = "[32m INFO"
    WARN = "[33m WARN"
    ERROR = "[31mERROR"


def log(level: LogLevel, message: str) -> None:
    """Logs a message to stdout with the given level"""
    print(f"\033{level.value}\033[0m {message}")
