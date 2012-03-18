USING: io kernel math math.parser math.functions sequences ;

  0
  readln
  [
    40 =
    [
      1 +
    ]
    [
      1 -
    ]
    if
    dup
    0 <
  ]
  filter
  length
  0 >
  [
    drop
    "NO"
    print
  ]
  [
    0 =
    [ "YES" ]
    [ "NO" ]
    if
    print
  ]
  if
