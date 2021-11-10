package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
)

var (
	sc             = bufio.NewScanner(os.Stdin)
	ScanErr        = errors.New("failed Scan")
	zeroDivErr     = errors.New("zero devision")
	nilErr         = errors.New("nil error")
	negativeValErr = errors.New("negativa value error")
)

// CLI manages given data
type CLI struct {
	n int
	m int
	k int
}

// NewCLI generates a pointer to CLI struct
func NewCLI() *CLI {
	return &CLI{}
}

// Scan scans given data and assgin cli field
// validation is also done in this function
func (c *CLI) Scan() error {
	sc.Split(bufio.ScanWords)

	if _, err := fmt.Scanf("%d %d %d", &c.n, &c.m, &c.k); err != nil {
		return err
	}

	return nil
}

// Solve solves given problem
// m人でn個のsushiを分け合う、maxでk個
// 最適なのは、k-1で分割して、余ったsushiの数だけ引く感じ
// n <= m * k なので食べ切れるのは保証される
func (c *CLI) Solve() error {
	rest := c.n - c.m*(c.k-1)

	// 全員2次会に行く
	if rest < 0 {
		fmt.Println(c.m)
	} else {
		fmt.Println(c.m - rest)
	}

	return nil
}
