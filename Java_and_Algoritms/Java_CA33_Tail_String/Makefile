# Makefile for CA3 Tail program

# Usage:
# To compile the program and tests: make all
# To run the program on sample.txt: make run
# To run the program on all provided txt files with k = 20: make run-tests
# To run manual invalid input checks: make run-invalid-tests
# To run JUnit tests: make junit
# To clean up compiled class files: make clean

# Directories
SRC = src
BIN = bin
DATA = data
LIB = lib

# Files and classes
MAIN = Tail
TEST = TailTest
JUNIT_JAR = $(LIB)/junit-platform-console-standalone-6.0.3.jar

# Detect platform and choose classpath separator
ifeq ($(OS),Windows_NT)
	CP_SEP = ;
else
	CP_SEP = :
endif

# Compile program and JUnit tests
compile:
	mkdir -p $(BIN)
	javac -cp "$(JUNIT_JAR)$(CP_SEP)$(SRC)" -d $(BIN) \
	$(SRC)/Tail.java \
	$(SRC)/TailTest.java
	echo "Compiled!"

# Run the app on sample.txt
run: compile
	java -cp $(BIN) $(MAIN) 5 < $(DATA)/sample.txt
	echo ""

# Run app on all provided txt files with k = 20
run-tests: compile
	echo ""
	echo "Running sample.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/sample.txt
	echo ""

	echo "Running 1Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/1Kints.txt
	echo ""

	echo "Running 2Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/2Kints.txt
	echo ""

	echo "Running 4Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/4Kints.txt
	echo ""

	echo "Running 8Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/8Kints.txt
	echo ""

	echo "Running largeT.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/largeT.txt
	echo ""

	echo "Running largeW.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/largeW.txt
	echo ""

	echo "Running medTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/medTale.txt
	echo ""

	echo "Running MobyDick.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/MobyDick.txt
	echo ""

	echo "Running tinyT.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyT.txt
	echo ""

	echo "Running tinyTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyTale.txt
	echo ""

	echo "Running tinytinyTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinytinyTale.txt
	echo ""

	echo "Running tinyW.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyW.txt
	echo ""

# Manual invalid input checks
run-invalid-tests: compile
	echo ""
	echo "Testing missing argument"
	java -cp $(BIN) $(MAIN)
	echo ""

	echo "Testing k = 0"
	java -cp $(BIN) $(MAIN) 0 < $(DATA)/sample.txt
	echo ""

	echo "Testing k = -1"
	java -cp $(BIN) $(MAIN) -1 < $(DATA)/sample.txt
	echo ""

	echo "Testing invalid string input"
	java -cp $(BIN) $(MAIN) abc < $(DATA)/sample.txt
	echo ""

# Run JUnit tests
junit: compile
	java -jar $(JUNIT_JAR) execute --class-path $(BIN) --scan-class-path

# Remove compiled class files
clean:
	rm -f $(BIN)/*.class