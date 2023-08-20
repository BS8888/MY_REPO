gcc ex2.c -o program -lm

for input_file in tests/*.in; do
    output_file="${input_file%.in}.out" 
    expected_output=$(cat "$output_file") 
    actual_output=$(./program < "$input_file") 

    if [ "$actual_output" = "$expected_output" ]; then
        echo "Test passed for $input_file"
    else
        echo "Test failed for $input_file"
        echo "Expected output: $expected_output"
        echo "Actual output: $actual_output"
    fi
done

rm program