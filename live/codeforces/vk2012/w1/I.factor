USING: io kernel math math.parser math.functions sequences ;

IN: template

: prime ( n -- answer )
  dup
  1 =
  [ drop 1 ]
  [
    0
    swap
    2
    [ 2dup dup * >= ]
    [
      rot
      2over
      mod
      0 =
      [
        1 +
      ]
      [ ]
      if
      -rot
      1 +
    ]
    while
    drop
    drop
  ]
  if
;

  readln
  dup
  [ 48 = ]
  filter
  length
  0 >
  [
    "NO" print
    drop
  ]
  [
    0
    swap
    dup
    string>number
    swap
    length
    10
    swap
    [
      rot
      2over
      mod
      prime
      +
      -rot
      10 *
    ]
    times
    drop
    drop
    0 =
    [ "YES" ]
    [ "NO" ]
    if
    print
  ]
  if
