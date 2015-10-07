var findMedianSortedArrays = function(A, B) {

    var median = function(A) {
        var m = A.length / 2;
        return A.length % 2 === 0 ? (A[m] + A[m - 1]) / 2 : A[Math.floor(m)];
    }
    
    var search = function(array, target, start, dest) {
        if ((dest - start) === 1) {
            return array[start] < target ? start : start - 1;
        }
        var middle = Math.floor((start + dest) / 2);
        var value = array[middle];
        if (value === target) {
            for (var i = middle - 1; i >= start; --i) {
                if (array[i] !== value) {
                    return i + 1;
                }
            }
        }
        if (value < target) {
            return search(array, target, middle, dest);
        } else {
            return search(array, target, start, middle);
        }
    }

    var find = function(L, R, P) {
        var l = L.length;
        var r = R.length;

        if (l === 0) {
            return R[P - 1];
        }
        if (r === 0) {
            return L[P - 1];
        }
        if ((l + r) === P) {
            return L[l - 1] > R[r - 1] ? L[l - 1] : R[r - 1];
        }
        if (P === 1) {
            return L[0] < R[0] ? L[0] : R[0];
        }

        var pl = Math.floor(l / 2);
        var pr = search(R, L[pl], 0, r);
        var left = pl + pr + 1;
        var right = (l - pl - 1) + (r - pr - 1);

        if (P === (left + 1)) {
            return L[pl];
        }
        if (P <= left) {
            if (pr === -1) {
                return L[pl - 1];
            }
            L.splice(pl, l - pl);
            R.splice(pr + 1, r - pr - 1);
            return find(L, R, P);
        } else {
            L.splice(0, pl + 1);
            R.splice(0, pr + 1);
            return find(L, R, P - left - 1);
        }
    }

    var m = A.length;
    var n = B.length;
    var middle = (m + n) / 2;

    if (m === 0) {
        return median(B);
    }

    if (n === 0) {
        return median(A);
    }

    return (m + n) % 2 === 0 ? (find(A.slice(0), B.slice(0), middle) +
        find(A.slice(0), B.slice(0), middle + 1)) / 2 :
        find(A.slice(0), B.slice(0), Math.floor(middle) + 1);
};
