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
		var k int
		var ans int64
		Fscan(in, &n, &k)
		a := make([]int64, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		ans = -1000000000
		for i := n - 205; i < n; i++ {
			if i < 0 {
				continue
			}
			for j := i + 1; j < n; j++ {
				ans = max(ans, int64(i+1)*int64(j+1)-int64(k)*(a[i]|a[j]))
			}
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
