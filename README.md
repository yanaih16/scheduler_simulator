# Scheduler_simulator
- アルゴリズム
  - 到着順
  - 処理時間順
  - ラウンドロビン

## 使い方
```bash
make
./build//schefuler_simulator
```
### ファイル入力
ファイル入力では`task.txt`を参照する。  
入力は以下の形式  
T:タスクの数  
A<sub>i</sub>:タスクiの名前  
B<sub>i</sub>:タスクiの到着時間  
C<sub>i</sub>:タスクiの処理時間  
>N  
>A<sub>1</sub> B<sub>1</sub> C<sub>1</sub>  
>A<sub>2</sub> B<sub>2</sub> C<sub>2</sub>  
>:  
>A<sub>i</sub> B<sub>i</sub> C<sub>i</sub>  
>:  
>A<sub>N-1</sub> B<sub>N-1</sub> C<sub>N-1</sub>    

### ランダム生成
ランダム生成は以下の範囲で生成される
>3<=N<=20  
>Aはアルファベット順  
>0<=B<=49  
>1<=C<=50  

生成されたものは'task.txt'に保存される
