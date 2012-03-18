USING: io kernel math math.parser math.functions sequences ;

  ""
  readln string>number
  2
  [
    2dup
    >=
  ]
  [
    2dup
    mod
    0 =
    [
      [
        2dup
        mod
        0 =
      ]
      [
        rot
        over
        number>string
        over
        length
        0 =
        [ append ]
        [
          swap
          "*" append
          swap
          append
        ]
        if
        -rot
        swap
        2dup
        swap
        /
        nip
        swap
      ]
      while
    ]
    [ ]
    if
    1 +
  ]
  while
  drop
  drop
  print

