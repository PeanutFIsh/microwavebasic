if [ ! -d "$bin" ]; then
	mkdir bin
fi

echo "Compiling MicrowaveBASIC Interpreter..."
g++ *.cpp libs/*.cpp -o bin/microwavebasic
echo "Done!"
