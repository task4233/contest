package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

// CLI manages given data
type CLI struct {
	n int
	k int
	s []int
	p []int
}

// NewCLI generates a pointer to CLI struct
func NewCLI() *CLI {
	return &CLI{}
}

// ScanInt scans int variable
func (c *CLI) ScanInt(val *int) error {
	var err error

	if !sc.Scan() {
		return ScanErr
	}
	if *val, err = strconv.Atoi(sc.Text()); err != nil {
		return fmt.Errorf("failed to Atoi: %w", err)
	}

	return nil
}

// Scan scans given data and assgin cli field
// validation is also done in this function
func (c *CLI) Scan() error {
	sc.Split(bufio.ScanWords)

	if _, err := fmt.Scanf("%d %d", &c.n, &c.k); err != nil {
		return err
	}

	for idx := 0; idx < c.n; idx++ {
		var tmp int
		var err error
		if !sc.Scan() {
			return ScanErr
		}
		tmp, err = strconv.Atoi(sc.Text())
		if err != nil {
			return fmt.Errorf("failed to Atoi: %w", err)
		}
		c.s = append(c.s, tmp)

		if !sc.Scan() {
			return ScanErr
		}
		tmp, err = strconv.Atoi(sc.Text())
		if err != nil {
			return fmt.Errorf("failed to Atoi: %w", err)
		}
		c.p = append(c.p, tmp)
	}
	return nil
}

// Solve solves given problem
func (c *CLI) Solve() error {

	return nil
}
