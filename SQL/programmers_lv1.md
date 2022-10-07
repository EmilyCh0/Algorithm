프로그래머스 SQL lv1
---
### 여러 기준으로 정렬하기
```mysql
SELECT ANIMAL_ID, NAME, DATETIME
FROM ANIMAL_INS
ORDER BY NAME ASC, DATETIME DESC
```
- 아이디와 이름, 보호 시작일을 조회한다.
- 이름 순으로 조회한다.
- 이름이 같으면 보호를 나중에 시작한 동물부터 조회한다.

### 동물의 아이디와 이름
```mysql
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```
- 아이디와 이름을 조회한다.
- 아이디 순으로 조회한다.

### 상위 n개 레코드
```mysql
SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME LIMIT 1
```
- 보호소에 가장 먼저 들어온 동물의 이름 조회

### 아픈 동물 찾기
```mysql
select animal_id, name
from animal_ins
where intake_condition = 'Sick'
order by animal_id
```
- 아픈 동물 조회 
- 아이디 순 조회

### 이름이 있는 동물의 아이디
```mysql
select animal_id
from animal_ins
where name is not NULL
order by animal_id
```
- 아이디 오름차순 조회
- 이름이 NULL이 아닌 동물 조회

### 어린 동물 찾기
```mysql
select animal_id, name
from animal_ins
where intake_condition != 'Aged'
order by animal_id
```
- 아이디와 이름 조회
- intake_condition이 Aged가 아닌 동물 조회

### 역순 정렬하기
```mysql
select name, datetime
from animal_ins
order by animal_id desc
```
- 이름, 보호 시작일 조회
- 아이디 역순 조회

### 모든 레코드 조회
```mysql
select * 
from animal_ins
order by animal_id
```
- 모든 레코드 아이디 순 조회
