@echo off 
del %1.com 
"C:\Program Files (x86)\NASM\NASM.exe" %1.asm -o %1.com
CrearDisco.exe %1.com