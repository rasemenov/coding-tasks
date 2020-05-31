func checkIfExist(arr []int) bool {
    if len(arr) == 0 {
        return false
    }
    index := make(map[int]int)
    for _, v := range arr {
        if _, ok := index[2*v]; ok {
            return true
        }
        if mod := (int(math.Abs(float64(v))) % 2) == 0; mod {
            if _, ok := index[v/2]; ok {
                return true
            }
        }
        index[v] = v
    }
    return false
}
