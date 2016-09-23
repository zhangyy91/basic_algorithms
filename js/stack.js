/**
 *
 * @param pushseq push sequence
 * @param popseq pop sequence to validate
 * @returns {boolean}
 */
function validate_seq(pushseq, popseq) {
    var stack = [];
    for (var i = 0, j = 0; j < popseq.length;) {
        if (i < pushseq.length)
            stack.push(pushseq[i++]);
        while (stack.length && stack[stack.length - 1] == popseq[j]) {
            stack.pop();
            ++j;
        }
        if (i >= pushseq.length)
            break;
    }
    return !stack.length;
}
validate_seq("123456789", "987654321");
validate_seq("123456789", "321654987");
validate_seq("123456789", "321459876");
validate_seq("123456789", "345129876");