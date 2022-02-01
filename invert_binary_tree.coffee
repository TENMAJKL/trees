tree = [
    [
        null,
        4,
        [
            null
            5,
            null
        ]
    ],
    3,
    [
        [
            null,
            1,
            [
                null,
                9,
                null
            ]
        ],
        6,
        [
            [
                null,
                8,
                null
            ],
            7,
            null
        ]
    ]
]

console.log tree

invert = (node) ->
    if node[0]
        node[0] = invert(node[0])
        node
    if node[2]
        node[2] = invert(node[2])
        node
    
    [node[0], node[2]] = [node[2], node[0]]
    node

console.log invert (tree)
