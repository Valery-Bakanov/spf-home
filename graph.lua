
local function name2node (graph, name) -- вернуть узел node по его имени name
 local node = graph[name]
 if not node then
  -- узла еще нет, надо создать новый
  node = { name = name, adj = {} }
  graph[name] = node
 end
 return node
end


function readgraph () -- чтение графа из файла
 local graph = {}
 io.write( "=> " )
 -- for line in io.lines ("graph.in") do
 for line in io.lines () do
 -- разбить строку на два имени
 local namefrom, nameto = string.match(line, "(%S+)%s+(%S+)")
 -- найти соответствующие узлы
 local from = name2node(graph, namefrom)
 local to = name2node(graph, nameto)
 -- добавить 'to' к списку связей узла 'from'
 from.adj[to] = true
 end
 return graph
end


function findpath (curr, to, path, visited) -- ищем путь между двумя узлами
 path = path or {} -- path = список узлов
 visited = visited or {} -- visited = множество узлов (не имён узлов)
 if visited[curr] then -- узел уже посещен?
  return nil -- здесь пути нет
 end
 visited[curr] = true -- пометим узел как посещенный
 path[#path + 1] = curr -- добавим к пути
 if curr == to then -- цель достигнута (конечный узел)?
  return path
 end
                    -- попробуем все соседние узлы
 for node in pairs(curr.adj) do
  local p = findpath (node, to, path, visited)
  if p then return p
  end
 end
 path[#path] = nil -- удалить узел из пути
end


function printpath (path) -- печать пути
 for i = 1, #path do
 print(path[i].name)
 end
end

--
-- начало выполнения
--
g = readgraph()
a = name2node(g, "a")
b = name2node (g, "b")
p = findpath (a, b)
if p then
 printpath (p)
end

