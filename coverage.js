var fs = require('fs'),
    xml2js = require('xml2js');
	
var parser = new xml2js.Parser();
var path = "TestResults";

fs.readdir( path, function( err, files ) {
	if( err ) {
		console.error( "Could not list the directory.\n", err );
		process.exit( 1 );
	}
	files.forEach( function( file, index ) {
		if(file.indexOf(".trx")>-1) {
			fs.readFile( path + "\\" + file, function( err, data ) {
				parser.parseString(data, function( err, result ) {
					var testResults = result.TestRun.ResultSummary[0].Counters[0]['$'];
					var testsDone = testResults.executed;
					var testsFailed = testResults.failed;
					console.log("(", ((testsDone - testsFailed)*100 / testsDone).toFixed(2), "%) of the tests suceeded.");
				} );
			} );
		}
		parser.reset();
	} );
});