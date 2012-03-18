USING: io kernel math math.parser math.functions sequences ;

IN: template

: ctoa ( n -- answer )
    dup
    65 <
    [ 48 - ]
    [ 65 - 10 + ]
    if
;

: atoc ( n -- answer )
    dup
    10 <
    [ 48 + ]
    [ 10 - 65 + ]
    if
;

: stoa ( n s -- n answer )
    0
    [
      -rot
      over
      *
      rot
      ctoa
      +
    ]
    reduce
;

  ""
  0
  readln string>number
  readln string>number
  swap
  [
    readln
    stoa
    rot
    +
    swap
  ]
  times
  swap
  dup
  0 =
  [
    "0"
    print
    drop
    drop
    drop
  ]
  [
    [ dup 0 > ]
    [
      rot
      2over
      swap
      mod
      atoc
      prefix
      -rot
      over
      /i
    ]
    while
    drop
    drop
    print
  ]
  if
