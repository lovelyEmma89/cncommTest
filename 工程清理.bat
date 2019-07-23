@echo off
del /s /a *.suo *.ncb *.user *.pdb *.netmodule *.aps *.lik *.sdf 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\debug" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\release" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\ipch" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\x64" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\.vs" 2>nul
rem FOR /R . %%d IN (.) DO rd /s /q "%%d\properties" 2>nul

echo 清理完成！
@ping 127.0.0.1 -n 3 >nul