var addTwoNumbers = function(l1, l2) {
    var lvalue = 0;
    var rvalue = 0;
    var carrier = 0;
    var sum = 0;
    var digit = 0;

    var answer = new ListNode(-1);
    var tail = answer;
    var node = null;

    while (l1 !== null || l2 !== null) {
        lvalue = l1 === null ? 0 : l1.val;
        l1 = l1 === null ? l1 : l1.next;
        rvalue = l2 === null ? 0 : l2.val;
        l2 = l2 === null ? l2 : l2.next;

        sum = lvalue + rvalue + carrier;
        digit = sum % 10;
        carrier = (sum - digit) === 0 ? 0 : 1;

        if (tail.val === -1) {
            tail.val = digit;
        } else {
            node = new ListNode(digit);
            tail.next = node;
            tail = node;
        }
    }

    if (carrier !== 0) {
        node = new ListNode(carrier);
        tail.next = node;
        tail = node;
    }

    return answer;
};
