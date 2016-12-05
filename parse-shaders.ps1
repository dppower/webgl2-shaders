$shaderDir = Join-Path $PSScriptRoot "shader-source"
$parserPath = "F:\dev\glsl\glsl-javascript-parser\Debug\glsl-javascript-parser.exe"
$shaderOutput = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot "..\build\game-data\shaders\"))
Write-Host "Parser path: $parserPath"
Write-Host "Output path: $shaderOutput"
$inputFileString = @()
Get-ChildItem -Path $shaderDir -Filter "*.glsl" | 
ForEach-Object {
    $inputFile = "$shaderDir\$($_.name)"
    $inputFileString += "`"$inputFile`""
    Write-Host "input file: $inputFile"    
}
&$parserPath -i $inputFileString -o $shaderOutput