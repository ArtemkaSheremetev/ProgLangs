#!/usr/bin/env bash
set -euo pipefail

EXE=out_prog.ptptb
LOGIN=${LOGIN:-"506858"}
PASSWORD=${PASSWORD:-"f082be5e-6c2e-4476-90e8-4035526d9d9d"}
ARC_FILE=reg32.target.pdsl
ARC=harvard32

MANAGER=(mono Portable.RemoteTasks.Manager.exe)

echo "Executing..."

"${MANAGER[@]}" -ul "$LOGIN" -up "$PASSWORD" -il -w -s \
 ExecuteBinaryWithInteractiveInput definitionFile "$ARC_FILE" \
 archName "$ARC" binaryFileToRun "$EXE" \
 ipRegStorageName ip finishMnemonicName hlt \
 codeRamBankName code stdinRegStName rin \
 stdoutRegStName rout 
