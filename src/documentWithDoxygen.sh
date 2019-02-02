if [ "$(uname -s)" == "MSYS_NT-10.0-WOW" ]; then
  echo Windows Build
  "c:\Program Files\doxygen\bin\doxygen.exe" doxygen.config
else
  echo Linux Build
  doxygen doxygen.config
fi
