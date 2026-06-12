@ECHO off
@REM If running from tools, move to project folder
if /i [%cd:~-5%]==[tools] cd ..

python ./tools/release.py --patch
