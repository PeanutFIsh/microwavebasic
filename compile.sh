echo "Compiling MicrowaveBASIC Interpreter..."

if [ ! -d "$bin" ]; then
	echo "bin/ does not exist. Creating directory..."
	mkdir bin
fi

if [ ! -d "$bin/programs" ]; then
	echo "bin/programs/ does not exist. Creating directory..."
	mkdir bin/programs
fi


g++ *.cpp libs/*.cpp -o bin/microwavebasic
echo "Done!"
