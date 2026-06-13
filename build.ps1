$cmake = "D:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
   Set-Location "D:\Documents\Documents\Tech\SuperTimecodeConverter"
   & $cmake --build build --config Release -j 8 2>&1