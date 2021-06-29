package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var k int
	Fscan(in, &k)
	for i := 0; i < k; i++ {
		var n, t, x int
		Fscan(in, &n, &x, &t)
		cnt := int64(min(n-1, int(t/x)))
		var ans int64
		ans += cnt * (int64(n-1) - cnt)
		ans += (cnt + 1) * cnt / 2
		Fprintln(out, ans)
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}
