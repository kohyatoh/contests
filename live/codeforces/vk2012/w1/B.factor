USING: io kernel math math.parser math.functions sequences ;

  ""
  readln string>number
  [
    dup
    0 >
  ]
  [
    swap
    over
    2 mod
    number>string
    swap
    append
    swap
    2 /i
  ]
  while
  drop
  print
