USING: io kernel math math.parser math.functions sequences ;

  readln
  [
    dup
    72 =
    [ 1 1 = ]
    [
      dup
      81 =
      [ 1 1 = ]
      [
        dup
        57 =
      ]
      if
    ]
    if
    nip
  ]
  filter
  length
  0 >
  [ "YES" print ]
  [ "NO" print ]
  if
