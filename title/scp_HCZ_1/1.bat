# 生成5个测试用例
python data_generator.py --num-cases 5

# 生成更复杂的测试用例（更大迷宫，更多步数）
python data_generator.py --size 50 --min-steps 200 --max-steps 450

# 使用特定种子
python data_generator.py --seed 12345