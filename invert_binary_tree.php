<?php

$node = [
    [
        null,
        10,
        null
    ],
    5,
    [
        [
            null,
            3,
            [
                null,
                2,
                null
            ]
        ],
        10,
        [
            null,
            1,
            null
        ]
    ]
];

/**
 * Inverts binary tree
 * 
 * @param array &$node
 */
function invert(&$node)
{
    if ($node[0])
        invert($node[0]);
    if ($node[2])
        invert($node[2]);

    $help = $node[2];
    $node[2] = $node[0];
    $node [0] = $help;
}


invert($node);
print_r($node);
