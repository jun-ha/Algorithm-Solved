SELECT 
    COUNT(*)
FROM
    (SELECT DISTINCT
        NAME
    FROM
        ANIMAL_INS
    WHERE
        NAME IS NOT NULL) AS A
    
