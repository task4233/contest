package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
)

var (
	sc             = bufio.NewScanner(os.Stdin)
	ScanErr        = errors.New("failed Scan")
	zeroDivErr     = errors.New("zero devision")
	nilErr         = errors.New("nil error")
	negativeValErr = errors.New("negativa value error")
)

const MOD = 100003

// CLI manages given data
type CLI struct {
	n int
	c []int
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

	if _, err := fmt.Scanf("%d", &c.n); err != nil {
		return err
	}
	c.c = make([]int, c.n)

	for idx := 0; idx < c.n; idx++ {
		var tmp int
		var err error
		if !sc.Scan() {
			return ScanErr
		}
		tmp, err = strconv.Atoi(sc.Text())
		if err != nil {
			return fmt.Errorf("failed Atoi: %w", err)
		}
		c.c[idx] = tmp
	}
	return nil
}

// Solve solves given problem
func (c *CLI) Solve() error {
	ans := 2
	for idx := 0; idx < c.n-2; idx++ {
		ans *= 2
		ans %= MOD
	}
	fmt.Println(ans)
	return nil
}
