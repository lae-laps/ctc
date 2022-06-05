#!/usr/bin/bash


if [ "$EUID" -ne 0 ]; then
    echo "[#] => Please run this script as root"
    exit
fi

echo "[*] => This script will install ctc in your system"

cp ctc.py /usr/local/bin/ctc
chmod a+x /usr/local/bin/ctc

echo "[+] => ctc was installed correctly"

