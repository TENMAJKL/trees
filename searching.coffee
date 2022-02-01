tree = [
    [
        null,
        12,
        [
            null,
            11,
            null
        ]
    ],
    9,
    [
        null,
        6,
        [
            [
                null,
                7,
                null
            ]
            5,
            [
                null,
                3,
                null
            ]

        ]
    ]
]

search = (node) -> (value) ->
    if !node
        null
    else
        if node[1] == value
            value
        else
            if value > node[1]
                search(node[0])(value)
            else
                search(node[2])(value)

console.log search(tree)(37)
console.log search(tree)(3)
console.log search(tree)(6)
console.log search(tree)(11)
