package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	solve := func() {
		var n int
		var ans int64
		Fscan(in, &n)
		a := make([]int64, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		for i := 1; i < n; i++ {
			ans = max(ans, a[i]*a[i-1])
		}
		Fprintln(out, ans)
	}
	var T int
	Fscan(in, &T)
	for i := 0; i < T; i++ {
		solve()
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}
