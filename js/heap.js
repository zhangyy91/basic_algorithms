function adjust_heap(s, i, n) {
  var j = i * 2 + 1;
  var tmp = s[i];
  while(j <= n) {
    if(j < n && s[j] < s[j + 1])
      ++j;
    if(tmp >= s[j])
      break;
    s[(j - 1) >> 1] = s[j];
    j = j * 2 + 1;
  }
  s[(j - 1) >> 1]=tmp;
}
function make_heap(s, i, n) {
  if(typeof s == 'string')
    s = s.split("")
  for(i = (s.length - 1) >> 1; i >= 0; --i)
    adjust_heap(s, i, s.length - 1);
  if(typeof str == 'string')
    return s.toString();
  return s;
}
function heap_sort(s) {
  if(typeof s == 'string')
    s = s.split('')
  for(var i = s.length - 2; i >= 0; --i) {
    var tmp = s[i+1];
    s[i+1] = s[0];
    s[0] = tmp;
    adjust_heap(s, 0, i);
  }
  if(typeof s == 'string')
    return s.toString()
  return s;
}
var heap = make_heap([26,5,77,1,61,11,59,15,48,19]);
console.log(heap);
var heap = heap_sort(heap);
console.log(heap);