package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// errors
var (
	ScanErr = errors.New("failed Scan")
)

// CLI manages given data
type CLI struct {
	n int
	a []int
}

// NewCLI generates a pointer to CLI struct
func NewCLI() *CLI {
	return &CLI{}
}

// Scan scans given data and assgin cli field
// validation is also done in this function
func (c *CLI) Scan() error {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	if !sc.Scan() {
		return ScanErr
	}
	var err error
	if c.n, err = strconv.Atoi(sc.Text()); err != nil {
		return fmt.Errorf("failed to Atoi: %w", err)
	}

	for idx := 0; idx < c.n; idx++ {
		if !sc.Scan() {
			return ScanErr
		}
		val, err := strconv.Atoi(sc.Text())
		if err != nil {
			return fmt.Errorf("failed to Atoi: %w", err)
		}

		c.a = append(c.a, val)
	}

	return nil
}

// Solve solves given problem
func (c *CLI) Solve() error {
	
	return nil
}
