function Node(value, left, right) {
    this.value = value;
    this.left = left;
    this.right = right;
}

Node.prototype.toPreOrderString = function () {
    var string = this.value.toString();
    if (this.left)
        string += this.left.toPreOrderString();
    if (this.right)
        string += this.right.toPreOrderString();
    return string;
};
Node.prototype.toInOrderString = function () {
    var string = "";
    if (this.left)
        string += this.left.toInOrderString();
    string += this.value.toString();
    if (this.right)
        string += this.right.toInOrderString();
    return string;
};
Node.prototype.toPostOrderString = function () {
    var string = "";
    if (this.left)
        string += this.left.toPostOrderString();
    if (this.right)
        string += this.right.toPostOrderString();
    return string + this.value.toString();
};
/**
 *
 * @param inlist inorder string
 * @param prelist preorder string
 * @returns Node or null
 */
function recoverFromInAndPre(inlist, prelist) {
    if (inlist.length == 0 || prelist.length == 0)
        return null;
    var value = prelist[0];
    var pair = inlist.split(value);
    var left_inlist = pair[0];
    var right_inlist = pair[1];
    var left_prelist = prelist.slice(1, left_inlist.length + 1);
    var right_prelist = prelist.slice(left_inlist.length + 1);
    return new Node(value, recoverFromInAndPre(left_inlist, left_prelist), recoverFromInAndPre(right_inlist, right_prelist));
}
/***
 *
 * @param inlist inorder string
 * @param postlist postorder string
 * @returns Node or null
 */
function recoverFromInAndPost(inlist, postlist) {
    if (inlist.length == 0 || postlist.length == 0)
        return null;
    var value = postlist[postlist.length - 1];
    var pair = inlist.split(value);
    var left_inlist = pair[0];
    var right_inlist = pair[1];
    var left_postlist = postlist.slice(0, left_inlist.length);
    var right_postlist = postlist.slice(left_inlist.length, postlist.length - 1);
    return new Node(value, recoverFromInAndPost(left_inlist, left_postlist), recoverFromInAndPost(right_inlist, right_postlist));
}
var root = recoverFromInAndPre("BCAEDGHFI", "ABCDEFGHI");
var root2 = recoverFromInAndPost("BCAEDGHFI", "CBEHGIFDA");