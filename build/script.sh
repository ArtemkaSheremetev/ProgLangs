#!/bin/bash

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s Assemble definitionFile reg32.target.fixed4.pdsl archName harvard32 asmListing program.s
sleep(2)

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s AssembleWithIncludes definitionFile reg32.target.fixed4.pdsl archName harvard32 binariesToInclude library1.s asmListing program.s

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s Assemble definitionFile reg32.target.fixed4.pdsl archName harvard32 asmListing library1.s
sleep(10)

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -g 25d71b6b-de0a-4ca9-9bc3-8b581aac045f -r"out.ptptb" -o "outlib.ptptb"
sleep(10)

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s AssembleWithIncludes definitionFile reg32.target.fixed4.pdsl archName harvard32 binariesToInclude outlib.ptptb asmListing program.s
sleep(10)

mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s ExecuteBinaryWithInteractiveInput definitionFile reg32.target.fixed4.pdsl archName harvard32 binaryFileToRun outprog.ptptb stdinRegStName rin stdoutRegStName rout codeRamBankName code ipRegStorageName ip finishMnemonicName hlt


mono Portable.RemoteTasks.Manager.exe -ul 506858 -up f082be5e-6c2e-4476-90e8-4035526d9d9d -v -s AssembleDebug definitionFile reg32.target.fixed4.pdsl archName harvard32 asmListing program.s sourcesDir  "/home/artem/study/yap/lab1ANTLR/build"