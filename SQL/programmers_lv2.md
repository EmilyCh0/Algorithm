프로그래머스 SQL lv2
---
### 중복 제거하기
```mysql
select count(distinct name)
from animal_ins
```
- NULL과 중복 제외한 이름의 수 구하기

### 최솟값 구하기
```mysql
select datetime
from animal_ins
order by datetime limit 1
```
- 보호소에 가장 먼저 들어온 동물이 언제 들어왔는지 조회

### 동물 수 구하기
```mysql
select count(distinct animal_id)
from animal_ins
```

### 이름에 el이 들어가는 동물 찾기
```mysql
select animal_id, name
from animal_ins
where animal_type = "Dog" and name like "%el%"
order by name
```
- 개
- 이름에 el이 들어감
- 이름 순 정렬
- (참고) `"_el_"` 는 앞 뒤로 글자 하나씩
