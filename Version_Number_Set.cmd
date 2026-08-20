start /w ..\projucer\Projucer.exe .\GuitarFineTune.jucer
call code.cmd .\snap\snapcraft.yaml .\snap\gui\guitarfinetune.desktop
start /w "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\devenv.exe" .\Builds\VisualStudio2026\GuitarFineTune.sln
D:\Program_Files\SmartGit\bin\smartgit.exe .
