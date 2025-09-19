import json
import ast

def jsonToDict( jsonStr, myList ):
    jsonStr = jsonStr[jsonStr.find("{"):jsonStr.rfind("}")+1] # Cut away any crap at the ends

    # Want to grab the first dict. But must make sure to corectly match braces.
    startIndex = 0
    nBraces = 0
    for index, i in enumerate(jsonStr):
        if nBraces == 0:
            if i != '{':
                continue
        if i == '{':
            if nBraces == 0:
                startIndex = index
            nBraces += 1
        elif i == '}':
            nBraces -= 1
        if nBraces == 0:
            #print(jsonStr[startIndex:index+1])
            myList.append( ast.literal_eval(jsonStr[startIndex:index+1]) )

def read_file():

    # read file
    with open('mc_metadata.json','r') as infile:
        data=infile.read()
    infile.close

    # parse file
    metadata_list = []
    jsonToDict(data,metadata_list)
        
    # create lists of important variables
    filenames=[]
    k_factors=[]
    generator_filter_efficiencies=[]
    cross_sections=[]
    weights=[]

    # define lists with all filenames, k_factors, generator_filter_efficiencies and cross_sections
    for element in metadata_list:
        if "name" in element:
            filenames.append(str(element["name"]))
        if "k_factor" in element:
            k_factors.append(float(element["k_factor"]))
        if "generator_filter_efficiency" in element:
            generator_filter_efficiencies.append(float(element["generator_filter_efficiency"]))
        if "cross_section" in element:
            cross_sections.append(float(element["cross_section"]))
 
    # cycle through filename list, calculate weight and add it to weights list
    for j in range(len(filenames)):
        value=k_factors[j]*generator_filter_efficiencies[j]*cross_sections[j]
        weights.append(value)
 
    # create dict with name:weight
    total_weights={}
    for i in range(len(filenames)):
        total_weights[filenames[i]] = weights[i]

    return total_weights
