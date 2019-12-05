# API Document

## src/engine/engine.h

### Classes

#### calculator::Engine

##### Member Types
|Member Type|Definition|
|---|---|
|Operator||
|Constant||

##### Member Functions
|Member Function|Definition|
|---|---|
|(Constructor)||
|Register||
|IsOperator||
|IsFunction||
|IsConstant||
|GetOperator||
|GetConstant||
|Evaluate||
|History||
|ClearHistory||
|Reset||
|Functions||
|Constants||
|Operators||
|Version||

### Functions
|Function|Definition|
|---|---|
|Version||

## src/c-api/c-api.h

### Enums
|Enum|Definition|
|---|---|
|EngineStatusCode||

### Structures
|Structure|Definition|
|---|---|
|_Engine||
|Engine||

### Functions
|Function|Definition|
|---|---|
|NewEngine||
|FreeEngine||
|IsOk||
|GetErrorMessage||
|Evaluate||
|ClearError||
|Version||

# src/version.h

### Variables

| Variable   | Definition |
| ---------- | ---------- |
| GIT_REV    |            |
| GIT_TAG    |            |
| GIT_BRANCH |            |


