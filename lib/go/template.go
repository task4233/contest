package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type CLI struct {
	n int
	a []int
}

func NewCLI() *CLI {
	return &CLI{}
}

func (c *CLI) Scan() error {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	var err error
	if c.n, err = strconv.Atoi(sc.Text()); err != nil {
		return fmt.Errorf("failed to Atoi: %w", err)
	}

	for idx := 0; idx < c.n; idx++ {
		sc.Scan()
		val, err := strconv.Atoi(sc.Text())
		if err != nil {
			return fmt.Errorf("failed to Atoi: %w", err)
		}

		c.a = append(c.a, val)
	}

	return nil
}

func (c *CLI) Solve() error {
	return nil
}
