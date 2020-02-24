package main

func main() {}

func strStr(haystack string, needle string) int {
	// short-circuit some cases
	if len(haystack) < len(needle) {
		return -1
	}
	if len(needle) == 0 {
		return 0
	}

	table := TableFor(needle)

	for i := 0; i < len(haystack); i++ {
		for j := 0; j < len(table); j++ {
			// no possible match
			if i+j >= len(haystack) {
				return -1
			}

			match := needle[j] == haystack[i+j]
			// exact match
			if j+1 == len(table) && match {
				return i
			}
			if match {
				continue
			}

			// pattern[j]!=text[i+j]
			// and we know that
			//          pattern[0]=pattern[j-table[j]]
			//             ...    =      ...
			// pattern[table[j]-1]=pattern[j-1]
			// which effectively mean:
			//             text[i]=pattern[j-table[j]]
			// so we now move:
			//                   i=i+j-table[j]
			i += (j - table[j]) - 1
			break
		}
	}
	return -1
}

// TableFor returns an failure value array for the pattern to move forward.
func TableFor(pattern string) []int {
	table := make([]int, len(pattern))

	for i := range pattern {
		if i == 0 || i == 1 {
			table[i] = i - 1
			continue
		}

		// define
		//       p[0]=p[j-k]
		//       p[1]=p[j-k+1]
		//        ..    ..
		//     p[k-1]=p[j-1]
		// as
		//       f(j)=k
		// now:
		//        p[k]=p[j] <==> f(j+1)=k+1
		//   p[f(j-1)]=p[j] <==> f(j+1)=f(j-1)+1
		//         ...      <==>     ...
		if pattern[table[i-1]] == pattern[i-1] {
			table[i] = table[i-1] + 1
		} else {
			// now look backward
			backward := table[i-1]
			for backward >= 0 {
				if pattern[backward] == pattern[i-1] {
					break
				} else {
					backward = table[backward]
				}
			}
			table[i] = backward + 1
		}
	}

	return table
}
