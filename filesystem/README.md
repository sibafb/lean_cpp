## filesystem library 

```
./filesystem_pick_extension.cpp
```


### filesystem_pick_extension.cpp

- Target Directory

```
filesystem$ tree samplefiles/
samplefiles/
├── bar.tar.gz
├── foo
│   └── bar.json
├── foobar
├── foo_bar.txt
└── foo.json
```

- Execution result

```
filesystem/build$ ./filesystem 
"../samplefiles/foo.json"
```