package main

import (
	"fmt"
	"os"
)

func main() {
	cli := NewCLI()
	if err := cli.Scan(); err != nil {
		fmt.Fprintf(os.Stderr, "failed to Scan: %s", err.Error())
		os.Exit(1)
	}

	if err := cli.Solve(); err != nil {
		fmt.Fprintf(os.Stderr, "failed to Solve: %s", err.Error())
		os.Exit(1)
	}
}
