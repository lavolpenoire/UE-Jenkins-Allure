@echo off

rem Engine params
set EnginePath_4.27=D:\Software\Unreal\UE_4.27
set EnginePath_5.1=D:\Software\Unreal\UE_5.1

set UBTRelativePath4=Engine\Binaries\DotNET\UnrealBuildTool.exe
set UBTRelativePath5=Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe 
set VersionSelector=C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe

rem Current engine path
set CurrentEnginePath=%EnginePath_5.1%

rem Editor path (Note: path for UE4: "..\UE4Editor.exe", for UE5: "..\UnrealEditor.exe")
set EditorPath=%CurrentEnginePath%\Engine\Binaries\Win64\UnrealEditor.exe

:: C:\Program Files\Epic Games\UE_5.0\Engine\Binaries\Win64\UnrealEditor.exe

rem !! Engine version for packaging !!
set RunUATPath=%CurrentEnginePath%\Engine\Build\BatchFiles\RunUAT.bat

rem Project params
set ProjectRoot=D:\Projects\UE5\LearningReports
set ProjectPureName=LearningReports
set ProjectName=%ProjectPureName%.uproject
set ProjectPath=%ProjectRoot%\%ProjectName%

rem Build params
set Platform=Win64
set Configuration=Development
set ArchivePath=%ProjectRoot%\Build

rem Other params
set SourceCodePath=%ProjectRoot%\Source
set dirsToRemove=Intermediate DerivedDataCache Saved Binaries .vs Build
set filesToRemove=*.sln

rem Target params
set COPYRIGHT_LINE=// My game copyright
set EXTRA_MODULE_NAMES="%ProjectPureName%"
set TargetTemplateFilePath=%ProjectRoot%\devops\targets\GameModule.Target.cs.template

rem Run
set ServerExePath=%ProjectRoot%\Build\WindowsServer\%ProjectPureName%Server.exe
set ClientExePath=%ProjectRoot%\Build\WindowsClient\%ProjectPureName%Client.exe
set GameExePath=%ProjectRoot%\Build\WindowsNoEditor\%ProjectPureName%.exe

rem Tests
set TestOutputLogPath=%ProjectRoot%\Build\Tests\Tests.log
set ReportOutputPath=%ProjectRoot%\Build\Tests
set UEAutomationContentPath=%CurrentEnginePath%\Engine\Content\Automation
set TestNames=MyOwn
set OpenCPPCoveragePath=C:\Program Files\OpenCppCoverage\OpenCppCoverage.exe
