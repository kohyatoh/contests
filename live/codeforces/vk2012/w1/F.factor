USING: io kernel math math.parser math.functions sequences ;

  0
  readln
  string>number
  5
  [ 2dup >= ]
  [
    rot
    2over
    /i
    +
    -rot
    5 *
  ]
  while
  drop
  drop
  number>string
  print
