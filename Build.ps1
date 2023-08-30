# Set Java Includes and Global Address Object Library Path
$JavaIncludeDirectory1 = "C:\Program Files\Java\jdk-20\include"
$JavaIncludeDirectory2 = "C:\Program Files\Java\jdk-20\include\win32"
$GlobalAddrLibraryPath = $PSScriptRoot

# Run cl command
& 'cl' -I"$GlobalAddrLibraryPath" -I"$JavaIncludeDirectory1" -I"$JavaIncludeDirectory2" -Fe'mdGlobalAddrJavaWrapper.dll' 'mdGlobalAddrJavaWrapper.cpp' -link -DLL -LIBPATH:"$GlobalAddrLibraryPath" -DEFAULTLIB:'mdGlobalAddr.lib'

# Remove files
Remove-Item 'mdGlobalAddrJavaWrapper.exp' -ErrorAction SilentlyContinue
Remove-Item 'mdGlobalAddrJavaWrapper.obj' -ErrorAction SilentlyContinue
Remove-Item 'mdGlobalAddrJavaWrapper.lib' -ErrorAction SilentlyContinue

