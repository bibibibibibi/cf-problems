package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	solve := func() {
		var n int
		Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		sort.Slice(a, func(i, j int) bool {
			return a[i]&1 == 0
		})
		c := 0
		for l, v := range a {
			for r := l + 1; r < len(a); r++ {
				w := a[r]
				if gcd(v, w*2) > 1 {
					c++
				}
			}
		}
		Fprintln(out, c)
	}
	var T int
	Fscan(in, &T)
	for Case := 1; Case <= T; Case++ {
		solve()
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}
