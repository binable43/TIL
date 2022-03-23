## EasyDict

EasyDict는 dict 값에 속성으로 액세스할 수 있게 한다. (재귀적으로 작동) 파이썬 dict에 대한 자바스크립트와 유사한 속성법 표기법이다.

```python
>>> from easydict import EasyDict as edict
>>> d = edict({'foo':3, 'bar':{'x':1, 'y':2}})
>>> d.foo
3
>>> d.bar.x
1

>>> d = edict(foo=3)
>>> d.foo
3
```

구문 분석된 json을 이용할 때 매우 유용하다!

```python
>>> from easydict import EasyDict as edict
>>> from simplejson import loads
>>> j = """{
"Buffer": 12,
"List1": [
    {"type" : "point", "coordinates" : [100.1,54.9] },
    {"type" : "point", "coordinates" : [109.4,65.1] },
    {"type" : "point", "coordinates" : [115.2,80.2] },
    {"type" : "point", "coordinates" : [150.9,97.8] }
]
}"""
>>> d = edict(loads(j))
>>> d.Buffer
12
>>> d.List1[0].coordinates[1]
54.9
```

속성값들을 얻는 것 만큼이나 간단하게 세팅할 수 있다 :

```python
>>> d = EasyDict()
>>> d.foo = 3
>>> d.foo
3
```

이는 여전히 `dict` 이다!

```python
>>> d = EasyDict(log=False)
>>> d.debug = True
>>> d.items()
[('debug', True), ('log', False)]
```

인스턴스와 클래스 속성들은 일반 객체처럼 접근 가능하다.

### Reference
[https://pypi.org/project/easydict/](https://pypi.org/project/easydict/)
